/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMonitor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 22:13:04 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 17:47:37 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainMonitor.hpp"

MainMonitor::MainMonitor(void)
{
	
}

MainMonitor::MainMonitor(SDL_Renderer *ren, int posY)
{
	this->_ren = ren;
	this->_posX = 25;
	this->_posY = posY;
	this->_sizeW = 350;
	this->_sizeH = 140;
	this->_n = 0;

	this->_btn1.rect.x = this->_posX + 250;	
	this->_btn1.rect.y = this->_posY + 10;
	this->_btn1.rect.w = 40;
	this->_btn1.rect.h = 40;
	this->_btn1.active = false;
	this->_btn2.rect.x = this->_posX + 300;	
	this->_btn2.rect.y = this->_posY + 10;
	this->_btn2.rect.w = 40;
	this->_btn2.rect.h = 40;
	this->_btn2.active = false;

	this->_data.push_back(new MainModule);

	SDL_Surface *surface = IMG_Load("textures/left_frame.png");
	this->_back = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("textures/plus_on.png");
	this->_btn1.texOn = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("textures/minus_on.png");
	this->_btn2.texOn = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("textures/plus_off.png");
	this->_btn1.texOff = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("textures/minus_off.png");
	this->_btn2.texOff = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_FreeSurface(surface);

	this->_font = TTF_OpenFont("open-sans/OpenSans-Regular.ttf", 20);
}

MainMonitor::MainMonitor(MainMonitor const & src)
{
	*this = src;
}

MainMonitor::~MainMonitor(void)
{
	for (size_t i = 0; i < this->_data.size(); i++)
		delete this->_data[i];
	TTF_CloseFont(this->_font);
}

void			MainMonitor::nextModule(void)
{
	this->_n = this->_n + 1;
	if (this->_n >= static_cast<int>(this->_data.size()))
		this->_n = 0;
}

void			MainMonitor::prevModule(void)
{
	this->_n = this->_n - 1;
	if (this->_n < 0)
		this->_n = static_cast<int>(this->_data.size() - 1);
}

MainMonitor		&MainMonitor::operator=(MainMonitor const & src)
{
	if (this != &src)
	{
		this->_data = src._data;
		this->_n = src._n;
		this->_ren = src._ren;
		this->_posY = src._posY;
		this->_posX = src._posX;
		this->_sizeH = src._sizeH;
		this->_sizeW = src._sizeW;
		this->_back = src._back;
	}
	return (*this);
}

void				MainMonitor::setPosY(int posY)
{
	this->_posY = posY;
}

int					MainMonitor::getW(void)
{
	return (this->_sizeW);
}

int					MainMonitor::getH(void)
{
	return (this->_sizeH);
}

bool				MainMonitor::getBtn1(void)
{
	return (this->_btn1.active);
}

bool				MainMonitor::getBtn2(void)
{
	return (this->_btn2.active);
}

SDL_Rect			MainMonitor::getBtn1Rect(void)
{
	return (this->_btn1.rect);
}

SDL_Rect			MainMonitor::getBtn2Rect(void)
{
	return (this->_btn2.rect);
}

void				MainMonitor::btn1Active(void)
{
	this->_btn1.active = !this->_btn1.active;
}

void				MainMonitor::btn2Active(void)
{
	this->_btn2.active = !this->_btn2.active;
}

void				MainMonitor::renderTitle(void)
{
	SDL_Rect	rect;
	SDL_Color	text_color;
	SDL_Texture	*texture;
	SDL_Surface	*surface;

	text_color.r = 240;
	text_color.g = 240;
	text_color.b = 240;
	surface = TTF_RenderText_Solid(this->_font, this->_data[this->_n]->getTitle().c_str(), text_color);
	rect.x = this->_posX + 20;
	rect.y = this->_posY + 15;
	rect.w = surface->w * 0.9;
	rect.h = surface->h * 0.9;
	texture = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_RenderCopy(this->_ren, texture, NULL, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void				MainMonitor::renderText1(void)
{
	SDL_Rect	rect;
	SDL_Color	text_color;
	SDL_Texture	*texture;
	SDL_Surface	*surface;

	text_color.r = 240;
	text_color.g = 240;
	text_color.b = 240;
	surface = TTF_RenderText_Solid(this->_font, this->_data[this->_n]->getText1().c_str(), text_color);
	rect.x = this->_posX + 20;
	rect.y = this->_posY + 50;
	rect.w = surface->w;
	rect.h = surface->h;
	texture = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_RenderCopy(this->_ren, texture, NULL, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void				MainMonitor::renderText2(void)
{
	SDL_Rect	rect;
	SDL_Color	text_color;
	SDL_Texture	*texture;
	SDL_Surface	*surface;

	text_color.r = 240;
	text_color.g = 240;
	text_color.b = 240;
	surface = TTF_RenderText_Solid(this->_font, this->_data[this->_n]->getText2().c_str(), text_color);
	rect.x = this->_posX + 20;
	rect.y = this->_posY + 85;
	rect.w = surface->w;
	rect.h = surface->h;
	texture = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_RenderCopy(this->_ren, texture, NULL, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void				MainMonitor::renderButtons(void)
{
	if (this->_btn1.active)
		SDL_RenderCopy(this->_ren, this->_btn1.texOn, NULL, &this->_btn1.rect);
	else
		SDL_RenderCopy(this->_ren, this->_btn1.texOff, NULL, &this->_btn1.rect);
	if (this->_btn2.active)
		SDL_RenderCopy(this->_ren, this->_btn2.texOn, NULL, &this->_btn2.rect);
	else
		SDL_RenderCopy(this->_ren, this->_btn2.texOff, NULL, &this->_btn2.rect);
}

void				MainMonitor::render(void)
{
	SDL_Rect	rect;

	this->_data[this->_n]->update();
	rect.x = this->_posX;
	rect.y = this->_posY;
	rect.w = this->_sizeW;
	rect.h = this->_sizeH;
	SDL_RenderCopy(this->_ren, this->_back, NULL, &rect);
	this->renderTitle();
	this->renderText1();
	this->renderText2();
	this->renderButtons();
}
