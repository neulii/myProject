#include "Titlebar.h"
#include <iostream>

namespace neulii
{
   //Constructor
    TitleBar::TitleBar( sf::RenderWindow &window, 
                        bool buttonMinimize, 
                        bool buttonResize, 
                        bool ButtonMaximize)
    {
        
        m_window =&window;
        m_titleBarShape.setFillColor(m_titleBarColor);

    }

    void TitleBar::update(long dT)
    {
        // m_titleBarPosX = m_window->getPosition().x;
        // m_titleBarPosY = m_window->getPosition().y;
        
        m_titleBarPosX = 0;
        m_titleBarPosY = 0;
        m_titleBarLength = m_window->getSize().x;


        m_titleBarShape.setPosition(m_titleBarPosX, m_titleBarPosY);
        m_titleBarShape.setSize(sf::Vector2f(m_titleBarLength, m_titleBarHeight));



    }

    void TitleBar::render(sf::RenderWindow& window)
    {
        
        window.draw(m_titleBarShape);
       std::cout << m_titleBarLength << NL;

    }



}//namespace neulii
