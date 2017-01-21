#include <string>

class SysObject{
  int xCord,yCord;
  std::string name;

public:
  SysObject();
  //

  void setloc(int x, int y);

  int getlocx();

  int getlocy();
};
