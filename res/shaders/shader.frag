#version 330 core

#define MAX_ITERS 100 
#define PI 3.1415926538

uniform vec2 screenResolution;
uniform vec2 centerOffset;
uniform float zoom;

out vec4 out_Color;

vec2 iter(vec2 prev, vec2 num) {
    float x = (prev.x * prev.x) - (prev.y * prev.y) + num.x;
    float y = (2.0 * prev.x * prev.y) + num.y;

    return vec2(x, y);
}

int iters_count(vec2 pos) {
    vec2 prev = vec2(0, 0);

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
    
    vec2 pos = uv.xy * zoom + centerOffset;
   
    int itersCount = iters_count(pos);
    
    float normalizedItersCount = normalizeItersCount(itersCount);
    
		out_Color = vec4(normalizedItersCount, normalizedItersCount, normalizedItersCount, 1.0);
}
