#pragma once
#include <string>

class SysObject {
protected:
  int xCord,yCord;
  std::string name;

public:
  SysObject();

  void setloc(int x, int y);

  int getlocx();

  int getlocy();
};
