/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StandardMonitor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:46:43 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 18:35:41 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StandardMonitor.hpp"

StandardMonitor::StandardMonitor(void) : _top(*(new std::string))
{
	
}

StandardMonitor::StandardMonitor(SDL_Renderer *ren, int posY, std::string const & top) : _top(top)
{
	this->_ren = ren;
	this->_posX = 25;
	this->_posY = posY;
	this->_sizeW = 350;
	this->_sizeH = 250;
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

	this->_data.push_back(new CPUModule(this->_top));
	this->_data.push_back(new RAMModule(this->_top));
	this->_data.push_back(new NetworkModule(this->_top));
	this->_data.push_back(new DisksModule(this->_top));
	this->_data.push_back(new ProcessesModule(this->_top));
	this->_data.push_back(new LoadAverageModule(this->_top));
	

	SDL_Surface *surface = IMG_Load("textures/contrast_dot.png");
	this->_line1 = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("textures/contrast_dot_2.png");
	this->_line2 = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("textures/standardmodule.png");
	this->_back = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("textures/left_on.png");
	this->_btn1.texOn = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("textures/right_on.png");
	this->_btn2.texOn = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("textures/left_off.png");
	this->_btn1.texOff = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("textures/right_off.png");
	this->_btn2.texOff = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_FreeSurface(surface);

	std::memset(&this->_mon1, 0, sizeof(this->_mon1));
	std::memset(&this->_mon2, 0, sizeof(this->_mon2));

	this->_font = TTF_OpenFont("open-sans/OpenSans-Regular.ttf", 35);
}

StandardMonitor::StandardMonitor(StandardMonitor const & src) : _top(src._top)
{
	*this = src;
}

StandardMonitor::~StandardMonitor(void)
{
	for (size_t i = 0; i < this->_data.size(); i++)
		delete this->_data[i];
	TTF_CloseFont(this->_font);
}

void			StandardMonitor::nextModule(void)
{
	this->_n = this->_n + 1;
	if (this->_n >= static_cast<int>(this->_data.size()))
		this->_n = 0;
	std::memset(&this->_mon1, 0, sizeof(this->_mon1));
	std::memset(&this->_mon2, 0, sizeof(this->_mon2));
}

void			StandardMonitor::prevModule(void)
{
	this->_n = this->_n - 1;
	if (this->_n < 0)
		this->_n = static_cast<int>(this->_data.size() - 1);
	std::memset(&this->_mon1, 0, sizeof(this->_mon1));
	std::memset(&this->_mon2, 0, sizeof(this->_mon2));
}

StandardMonitor		&StandardMonitor::operator=(StandardMonitor const & src)
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
		this->_mon1 = src._mon1;
		this->_mon2 = src._mon2;
		this->_line1 = src._line1;
		this->_line2 = src._line2;
		this->_back = src._back;
	}
	return (*this);
}

void				StandardMonitor::setPosY(int posY)
{
	this->_posY = posY;
}

int					StandardMonitor::getW(void)
{
	return (this->_sizeW);
}

int					StandardMonitor::getH(void)
{
	return (this->_sizeH);
}

bool				StandardMonitor::getBtn1(void)
{
	return (this->_btn1.active);
}

bool				StandardMonitor::getBtn2(void)
{
	return (this->_btn2.active);
}

SDL_Rect			StandardMonitor::getBtn1Rect(void)
{
	return (this->_btn1.rect);
}

SDL_Rect			StandardMonitor::getBtn2Rect(void)
{
	return (this->_btn2.rect);
}

void				StandardMonitor::btn1Active(void)
{
	this->_btn1.active = !this->_btn1.active;
}

void				StandardMonitor::btn2Active(void)
{
	this->_btn2.active = !this->_btn2.active;
}

void				StandardMonitor::updateMon(void)
{
	for (int n = 0; n != 100; n++)
	{
		if (n == 99)
			this->_mon1[n] = this->_data[this->_n]->getData1();
		else
			this->_mon1[n] = this->_mon1[n + 1];
		if (n == 99)
			this->_mon2[n] = this->_data[this->_n]->getData2();
		else
			this->_mon2[n] = this->_mon2[n + 1];
	}
}

void				StandardMonitor::renderTitle(void)
{
	SDL_Rect	rect;
	SDL_Color	text_color;
	SDL_Texture	*texture;
	SDL_Surface	*surface;

	text_color.r = 190;
	text_color.g = 190;
	text_color.b = 190;
	surface = TTF_RenderText_Solid(this->_font, this->_data[this->_n]->getTitle().c_str(), text_color);
	rect.x = this->_posX + 20;
	rect.y = this->_posY;
	rect.w = surface->w;
	rect.h = surface->h;
	texture = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_RenderCopy(this->_ren, texture, NULL, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void				StandardMonitor::renderText1(void)
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
	rect.w = surface->w * 0.85;
	rect.h = surface->h * 0.85;
	texture = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_RenderCopy(this->_ren, texture, NULL, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void				StandardMonitor::renderText2(void)
{
	SDL_Rect	rect;
	SDL_Color	text_color;
	SDL_Texture	*texture;
	SDL_Surface	*surface;

	text_color.r = 220;
	text_color.g = 220;
	text_color.b = 220;
	surface = TTF_RenderText_Solid(this->_font, this->_data[this->_n]->getText2().c_str(), text_color);
	rect.x = this->_posX + 20;
	rect.y = this->_posY + 90;
	rect.w = surface->w * 0.7;
	rect.h = surface->h * 0.7;
	texture = SDL_CreateTextureFromSurface(this->_ren, surface);
	SDL_RenderCopy(this->_ren, texture, NULL, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void				StandardMonitor::renderButtons(void)
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

void				StandardMonitor::render(void)
{
	SDL_Rect	rect;

	this->_data[this->_n]->update();
	this->updateMon();
	rect.x = this->_posX;
	rect.y = this->_posY;
	rect.w = this->_sizeW;
	rect.h = this->_sizeH;
	SDL_RenderCopy(this->_ren, this->_back, NULL, &rect);
	for (int n = 0; n != 100; n++)
	{
		rect.x = this->_posX + n * 3 + 25;
		rect.y = this->_posY + (100 - this->_mon1[n]) + 130;
		rect.w = 3;
		rect.h = this->_mon1[n];
		SDL_RenderCopy(this->_ren, this->_line1, NULL, &rect);
		rect.y = this->_posY + (100 - this->_mon2[n]) + 130;
		rect.h = this->_mon2[n];
		SDL_RenderCopy(this->_ren, this->_line2, NULL, &rect);
	}
	this->renderTitle();
	this->renderText1();
	this->renderText2();
	this->renderButtons();
//	std::cout << this->_top << std::endl;
}
