# lamy
topdown rpg prototype
SDL_2.0.9 folder needs to be in the same folder as the project folder "Lamy" for the stuff to work.
*Just as a heads up*
Also, the properties of the Lamy project need to be set with the following changes (I don't know why
it didn't include this part when I uploaded the project):
Under C/C++ > General > Additional Include Directories:
click the drop down arrow and select <Edit>
  Click the add directory button and select SDL2\include
Under Linker > General > Additional Library Directories:
click the drop down arrow and select <Edit>
  Click the add directory button and select SDL2\lib\x86
Under Linker > Input > Additional Dependencies:
  click the dropdown arrow and select <Edit>
  enter SDL2.lib and press Enter and enter SDL2main.lib
  click OK
Under Linker > System > SubSystem:
  Choose: Windows (/SUBSYSTEM:WINDOWS)
Click Apply and then OK
