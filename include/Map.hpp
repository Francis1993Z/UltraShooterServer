#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include "Engine.hpp"
#include "Bonus.hpp"

class Map
{
    /// Toujours faire un delete!
    /// Sinon dans le cas des laserbeam ça fait
    /// une erreur de segmentation.
    /// Le delete appele le destructeur et certain destructeur
    /// sont très spécifique.
    std::list<Projectile *> ProjectilesArray;
    std::list<Entity *> EntityArray;

    std::list<Obstacle> lObstacles;
    std::list<Bonus *> lBonus;
    std::list<Wave> lWaves;

    std::map<std::string, sf::Texture> mObstacleTextures;

    EnnemyFactory factory;

    int width;
    int height;
    unsigned long ennemies_left;

    sf::Texture backgroundTexture;
    sf::Sprite background;

    std::string theme;

    Entity* EntityTouche;
    Player* localplayer;
    bool gameOver;

public:

    Map(std::string mapPath);
    ~Map();

    void draw();

    int getWidth() const;
    int getHeight() const;

    void setlocalPlayer(Player& newPlayer);
    void addEnnemy(Ennemy* e);
    void addPlayer(Player* a);
    void addProjectile(Projectile* p);

    //! rmProjectile
    /// cherche un projectile avec l'aide de son adresse
    /// dans la list de projectile et l'enleve.
    void rmProjectile(Projectile* p);

    void addObstacle(std::string obstacleTexturePath, int x, int y);
    void addWave(Wave w);

    bool loadNextWave();
    bool isCurrentWaveOver() const;

    std::string getTheme() const;

    void drawObstacles(sf::RenderWindow* window) const;
    void drawBonus() const;
    void update(sf::RenderWindow* game);

    sf::Sprite getBackground() const;

    sf::FloatRect getCollisionBox() const;

    std::list<Obstacle> getListeObstacles() const;

    bool getGameOver() const;
};



#endif // MAP_HPP_INCLUDED
