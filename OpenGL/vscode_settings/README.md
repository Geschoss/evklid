## OpenGl on mac

### Prepare

- OpenGL installation verification:
    
    OpenGL comes with the OS. To verify, check for: `/System/Library/Frameworks/OpenGL.framework`

- Be sure that you've run `xcode-setup --install`

- install GLFW

    can be instaled by `brew` or from [GLFW Source package](https://www.glfw.org/download.html)

- To make a GLFW application on the command line

    when linking your code, use the following linker options:
    `-lglfw -framework OpenGL`

    To link with the static GLFW library, use instead:

    `-lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo`