/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sdl.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:48:36 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 18:44:52 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sdl.hpp"

Sdl::Sdl(void)
{
	this->_winW = 200;
	this->_winH = 615 - 130;
	this->_t1 = clock() / (CLOCKS_PER_SEC / FPS);
	this->_t2 = clock() / (CLOCKS_PER_SEC / FPS);
	if (SDL_Init(SDL_INIT_EVERYTHING))
		return ;
	if (TTF_Init())
		return ;
	if (!(this->_win = SDL_CreateWindow("ft_gkrellm", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, this->_winW, this->_winH, SDL_WINDOW_SHOWN
								| SDL_WINDOW_ALLOW_HIGHDPI)))
		return ;
	if (!(this->_ren = SDL_CreateRenderer(this->_win, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		return ;
	SDL_SetRenderDrawColor(this->_ren, 100, 100, 100, 100);
	SDL_RenderClear(this->_ren);
	SDL_RenderPresent(this->_ren);
	this->_on = true;
	this->_changes = false;
	std::cout << "Sdl constructor success!" << std::endl;
	this->updateTop();
	this->_displays.push_back(new MainMonitor(this->_ren, 25));	
	this->_displays.push_back(new StandardMonitor(this->_ren, 175, this->_top));
	this->_displays.push_back(new StandardMonitor(this->_ren, 175 + 260, this->_top));
	this->_displays[2]->nextModule();
	this->_displays.push_back(new StandardMonitor(this->_ren, 175 + 260 + 260, this->_top));
	this->_displays[3]->nextModule();
	this->_displays[3]->nextModule();
}

Sdl::Sdl(Sdl const & src)
{
	*this = src;
}

Sdl::~Sdl(void)
{
	for (int i = this->_displays.size() - 1; i != -1; i--)
	{
		delete this->_displays[i];
		this->_displays.pop_back();
	}
	SDL_DestroyWindow(this->_win);
	TTF_Quit();
	SDL_Quit();
	std::cout << "Sdl destructor called!" << std::endl;
}

Sdl			&Sdl::operator=(Sdl const & src)
{
	if (this != &src)
	{
		this->_winW = src._winW;
		this->_winH = src._winH;
		this->_win = src._win;
		this->_ren = src._ren;
		this->_e = src._e;
		this->_on = src._on;
	}
	return (*this);
}

void		Sdl::updateTop(void)
{
	char		buffer[32];
	std::string	output;
	FILE		*stream = popen("/usr/bin/top -l 1 | sed '11, 333d'", "r");
	if (stream)
	{
		while (!feof(stream))
            if (fgets(buffer, 32, stream) != NULL) output.append(buffer);
        pclose(stream);
    }
	this->_top = output;
}

void		Sdl::loop(void)
{
	while (this->_on)
	{
		this->eHook();
		this->_t1 = clock() / (CLOCKS_PER_SEC / FPS);
		if (this->_t1 > this->_t2 || this->_changes == true)
		{
			this->updateTop();
			this->_t2 = clock() / (CLOCKS_PER_SEC / FPS);
			SDL_SetRenderDrawColor(this->_ren, 50, 50, 50, 50);
			SDL_RenderClear(this->_ren);
			for (size_t i = 0; i < this->_displays.size(); i++)
				this->_displays[i]->render();
			SDL_RenderPresent(this->_ren);	
			this->_changes = false;
		}
	}
}

void		Sdl::eHook(void)
{
	while (SDL_PollEvent(&this->_e))
	{
		if (this->_e.type == SDL_QUIT)
			this->_on = false;
		else if (this->_e.type == SDL_KEYDOWN)
			this->keyEvents(this->_e.key.keysym.sym);
		else if (this->_e.type == SDL_MOUSEBUTTONDOWN)
			this->mouseButtonDown(this->_e.button.x, this->_e.button.y);
		else if (this->_e.type == SDL_MOUSEBUTTONUP)
			this->mouseButtonUp(this->_e.button.x, this->_e.button.y);
		else if (this->_e.type == SDL_MOUSEMOTION)
			;
	}
}

void		Sdl::keyEvents(int key)
{
	if (key == SDLK_ESCAPE)
		this->_on = false;
}

static int	in_rect(int x, int y, SDL_Rect rect)
{
	if (x * 2 > rect.x && y * 2 > rect.y
			&& x * 2 < rect.x + rect.w
			&& y * 2 < rect.y + rect.h)
		return (1);
	else
		return (0);
}

void		Sdl::mouseButtonDown(int x, int y)
{
	for (size_t i = 0; i < _displays.size(); i++)
	{
		if (in_rect(x, y, _displays[i]->getBtn1Rect()))
		{
			_displays[i]->btn1Active();
			this->_changes = true;
		}
		if (in_rect(x, y, _displays[i]->getBtn2Rect()))
		{
			_displays[i]->btn2Active();
			this->_changes = true;
		}
	}
}

void		Sdl::mainModulButtonsActions(int x, int y)
{
	if (in_rect(x, y, _displays[0]->getBtn1Rect()))
	{
		if (_displays[0]->getBtn1() && _displays.size() < 7)
		{
			this->addDisplay();
		}
	}
	if (in_rect(x, y, _displays[0]->getBtn2Rect()))
	{
		if (_displays[0]->getBtn2() && _displays.size() != 1)
		{
			this->removeDisplay();
		}
	}
	if (_displays[0]->getBtn1())
	{
		_displays[0]->btn1Active();
		this->_changes = true;
	}
	if (_displays[0]->getBtn2())
	{
		_displays[0]->btn2Active();
		this->_changes = true;
	}
}

void		Sdl::mouseButtonUp(int x, int y)
{
	this->mainModulButtonsActions(x, y);
	for (size_t i = 1; i < _displays.size(); i++)
	{
		if (in_rect(x, y, _displays[i]->getBtn1Rect()))
		{
			if (_displays[i]->getBtn1())
				_displays[i]->prevModule();
		}
		if (in_rect(x, y, _displays[i]->getBtn2Rect()))
		{
			if (_displays[i]->getBtn2())
				_displays[i]->nextModule();
		}
		if (_displays[i]->getBtn1())
		{
			_displays[i]->btn1Active();
			this->_changes = true;
		}
		if (_displays[i]->getBtn2())
		{
			_displays[i]->btn2Active();
			this->_changes = true;
		}
	}
}

void		Sdl::addDisplay(void)
{
	this->_winH += 130;
	SDL_SetWindowSize(this->_win, this->_winW, this->_winH);
	this->_displays.push_back(new StandardMonitor(this->_ren, this->_winH * 2 - 275, this->_top));
}

void		Sdl::removeDisplay(void)
{
	this->_winH -= 130;
	SDL_SetWindowSize(this->_win, this->_winW, this->_winH);
	delete this->_displays[this->_displays.size() - 1];
	this->_displays.pop_back();
}




















