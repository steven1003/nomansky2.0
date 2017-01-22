class RscEntity{
public:
  std::string getName();
  int getNum();
  sf::Texture getTexture();
  void addItem(int num);
  RscEntity(std::string texturefile);
  void setTexture(sf::Texture text);

private:
  int numOf;
  sf::Texture rsctext;
  std::string name;



};
