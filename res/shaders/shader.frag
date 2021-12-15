#version 400 core

#define MAX_ITERS 100 
#define PI 3.1415926538

uniform vec2 screenResolution;
uniform vec2 centerOffset;
uniform float zoom;

out vec4 out_Color;

dvec2 iter(dvec2 prev, dvec2 num) {
    double x = (prev.x * prev.x) - (prev.y * prev.y) + num.x;
    double y = (2.0 * prev.x * prev.y) + num.y;

    return dvec2(x, y);
}

int iters_count(dvec2 pos) {
    dvec2 prev = dvec2(0, 0);

    for(int i = 0; i < MAX_ITERS; i++) {
        prev = iter(prev, pos);        
        
        if(length(prev) > 2.0) {
            return i;
        }    
    }
    
    return 0;
}

float normalizeItersCount(int count) {
    return sqrt(float(count) / float(MAX_ITERS));
}

void main()
{
		vec2 centerCoord = screenResolution.xy / 2;
		vec2 relCoord = gl_FragCoord.xy - centerCoord;

		vec2 uv = relCoord / screenResolution.x;
    
    dvec2 pos = uv.xy * zoom + centerOffset;
   
    int itersCount = iters_count(pos);
    
    float normalizedItersCount = normalizeItersCount(itersCount);
    
		out_Color = vec4(normalizedItersCount, normalizedItersCount, normalizedItersCount, 1.0);
}
