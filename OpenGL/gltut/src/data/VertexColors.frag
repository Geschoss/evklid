#version 330

smooth in vec4 theColor;

out vec4 outputColor;
uniform float u_time;

void main()
{
    
    float lerpValue = gl_FragCoord.x / 600.0f;
    
    outputColor = mix(theColor,
            vec4(0.1f, 0.1f, 0.1f, 1.0f), lerpValue);
}