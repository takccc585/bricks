﻿#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"

struct Ball {
	sf::CircleShape shape;
	float speedx, speedy;
	int leftScore, rightScore;
};
void ballInit(Ball& ball)
{
	//çàäàíèå íà÷àëüíûõ çíà÷åíèé äëÿ ôèãóðû (êðóã) 
	ball.shape.setRadius(ballRadius);
	ball.shape.setFillColor(ballColor);
	ball.shape.setPosition(BallStart);
	//çàäàíèå íà÷àëüíûõ çíà÷åíèé äëÿ ñêîðîñòåé
	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	int index = rand() % 10;
	ball.speedx = arr_speed[index];
	index = rand() % 10;
	ball.speedy = arr_speed[index];
	//çàäàíèå íà÷àëüíûõ çíà÷åíèé äëÿ ñ÷åòà
	ball.leftScore = 0;
	ball.rightScore = 0;
}
void ballReboundHorizontal(Ball& ball) {
	if (ball.shape.getPosition().x <= 0) {
		ball.speedx = -ball.speedx;
		ball.rightScore++;
	}
	if (ball.shape.getPosition().x >= (WINDOW_WIDTH - 2 * ballRadius)) {
		ball.speedx = -ball.speedx;
		ball.leftScore++;
	}
}

void ballReboundVertical(Ball& ball) {
	if (ball.shape.getPosition().y <= 0) {
		ball.speedy = -ball.speedy;
	}
	if (ball.shape.getPosition().y >= (WINDOW_HEIGHT - 2 * ballRadius)) {
		ball.speedy = -ball.speedy;
	}
}

void ballUpdate(Ball& ball) {
	ball.shape.move(ball.speedx, ball.speedy);
	ballReboundHorizontal(ball);
	ballReboundVertical(ball);
}

void ballDraw(sf::RenderWindow& window, Ball ball) {
	window.draw(ball.shape);
}
