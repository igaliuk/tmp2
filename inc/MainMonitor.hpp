/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainMonitor.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 22:10:45 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 17:47:30 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAINMONITOR_HPP
# define MAINMONITOR_HPP
# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"
# include "MainModule.hpp"
# include <iostream>
# include <array>
# include <vector>

class						MainMonitor : public IMonitorDisplay
{
	public:
		MainMonitor(void);
		MainMonitor(SDL_Renderer *ren, int posY);
		MainMonitor(MainMonitor const & src);
		~MainMonitor(void);
		MainMonitor			&operator=(MainMonitor const & src);
		void				render(void);
		void				setPosY(int posY);
		int					getH(void);
		int					getW(void);
		void				renderTitle(void);
		void				renderText1(void);
		void				renderText2(void);
		void				renderButtons(void);
		bool				getBtn1(void);
		bool				getBtn2(void);
		void				btn1Active(void);
		void				btn2Active(void);
		SDL_Rect			getBtn1Rect(void);
		SDL_Rect			getBtn2Rect(void);
		void				nextModule(void);
		void				prevModule(void);
	private:
		std::vector<IMonitorModule *>	_data;
		int					_n;
		SDL_Renderer		*_ren;
		int					_posX;
		int					_posY;
		int					_sizeH;
		int					_sizeW;
		SDL_Texture			*_back;
		TTF_Font			*_font;
		btn					_btn1;
		btn					_btn2;
};

#endif
