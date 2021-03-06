#version 460
        
layout( location = 0 ) in vec3 pos;        
layout( location = 1 ) in vec3 col;
layout( location = 2 ) in vec2 tex;

out vec3 aCol;
out vec2 texCoord;

uniform mat4 model;
uniform mat4 projection;

void main( void )
{
    aCol = col;
    texCoord = tex;
    gl_Position = projection * model * vec4( pos, 1.f );
}