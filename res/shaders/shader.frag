#version 330 core

#define MAX_ITERS 100 
#define PI 3.1415926538

uniform vec2 screenResolution;

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
    vec2 uv = gl_FragCoord.xy / screenResolution.xy;

    float scale = 4.0;
    vec2 offset = vec2(-2.0, -1.5);
    
    vec2 pos = vec2(uv.x, gl_FragCoord.y / screenResolution.x) * scale + offset;
   
    int itersCount = iters_count(pos);
    
    float normalizedItersCount = normalizeItersCount(itersCount);
    
		out_Color = vec4(normalizedItersCount, normalizedItersCount, normalizedItersCount, 1.0);
}
