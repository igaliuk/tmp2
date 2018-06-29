/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sdl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:44:33 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 15:40:10 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_HPP
# define SDL_HPP
# include "SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"
# include "IMonitorDisplay.hpp"
# include "StandardMonitor.hpp"
# include "MainMonitor.hpp"
# include <iostream>
# include <vector>
# define FPS 5

class					Sdl
{
	public:
		Sdl(void);
		Sdl(Sdl const & src);
		~Sdl(void);
		Sdl				&operator=(Sdl const & src);
		void			loop(void);
		void			eHook(void);
		void			keyEvents(int key);
		void			mouseButtonDown(int x, int y);
		void			mouseButtonUp(int x, int y);
		void			mainModulButtonsActions(int x, int y);
		void			addDisplay(void);
		void			removeDisplay(void);
	//	void			mouseMotion(int x, int y);
		void			updateTop(void);
	private:
		int				_winW;
		int				_winH;
		SDL_Window		*_win;
		SDL_Renderer	*_ren;
		SDL_Event		_e;
		bool			_on;
		bool			_changes;
		clock_t			_t1;
		clock_t			_t2;
		std::string		_top;
		std::vector<IMonitorDisplay *>	_displays;
};

#endif
