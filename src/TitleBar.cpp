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
        m_titleBarShape = new ClickableHooverableRectShape( 0,
                                                            0,
                                                            window.getSize().x,
                                                            m_titleBarHeight);
    }

    void TitleBar::update(long dT)
    {

        // m_titleBarPosX = m_window->getPosition().x;
        // m_titleBarPosY = m_window->getPosition().y;
        
        m_titleBarPosX = 0;
        m_titleBarPosY = 0;
        m_titleBarLength = m_window->getSize().x;

       
        m_titleBarShape->setPosition(m_titleBarPosX, m_titleBarPosY);
        m_titleBarShape->setSize(sf::Vector2f(m_titleBarLength, m_titleBarHeight));

        m_titleBarShape->setDefaultColor(m_titleBarColor);
       
        m_titleBarShape->update(dT);


        if(m_titleBarShape->isLeftButtonDown())
        {
            dragBegin = true;
            //std::cout << "vorher" << std::endl;
            if(!dragBegin){
                mouseDragBeginPosition = sf::Mouse::getPosition();
                vector2iToConsole(mouseDragBeginPosition);
            
            }
        
        }
        else
        {
            mouseDragBeginPosition = sf::Mouse::getPosition();
            dragBegin = false;

        }

        if(dragBegin)
        {
            //std::cout << "draging" << std::endl;
            m_window->setPosition(sf::Vector2i(m_window->getPosition().x-(mouseDragBeginPosition.x-sf::Mouse::getPosition().x),
                                  m_window->getPosition().y-(mouseDragBeginPosition.y-sf::Mouse::getPosition().y) ));
        mouseDragBeginPosition = sf::Mouse::getPosition();
        }
    }

    void TitleBar::render(sf::RenderWindow& window)
    {
       m_titleBarShape->render(window);
    
    }



}//namespace neulii
