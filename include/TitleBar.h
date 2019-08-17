#ifndef TITLEBAR_H
#define TITLEBAR_H

#include "SFML/Graphics.hpp"
#include "ClickableHooverableRectShape.h"

namespace neulii{

    class TitleBar
    {
    
    private:
        float m_titleBarHeight = 25;
        float m_titleBarLength;

        float m_titleBarPosX;
        float m_titleBarPosY;
        
        sf::RenderWindow *m_window;
        sf::Color m_titleBarColor = sf::Color::White;

        neulii::ClickableHooverableRectShape* m_buttonMinimize;
        neulii::ClickableHooverableRectShape* m_buttonResize;
        neulii::ClickableHooverableRectShape* m_buttonMaximize;

        neulii::ClickableHooverableRectShape* m_titleBarShape;

    public: 
        
        TitleBar(   sf::RenderWindow &window, 
                    bool buttonMinimize, 
                    bool buttonResize, 
                    bool ButtonMaximize);

        void update(long dT);
        void render(sf::RenderWindow& window);













    };
}//namespace neulii

#endif