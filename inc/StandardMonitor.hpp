/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StandardMonitor.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:41:32 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 18:33:21 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STANDARDMONITOR_HPP
# define STANDARDMONITOR_HPP
# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"
# include "CPUModule.hpp"
# include "RAMModule.hpp"
# include "NetworkModule.hpp"
# include "DisksModule.hpp"
# include "ProcessesModule.hpp"
# include "LoadAverageModule.hpp"
# include <iostream>
# include <array>
# include <vector>

class						StandardMonitor : public IMonitorDisplay
{
	public:
		StandardMonitor(SDL_Renderer *ren, int posY, std::string const & top);
		StandardMonitor(StandardMonitor const & src);
		~StandardMonitor(void);
		StandardMonitor		&operator=(StandardMonitor const & src);
		void				render(void);
		void				setPosY(int posY);
		int					getH(void);
		int					getW(void);
		void				updateMon(void);
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
		StandardMonitor(void);
		std::vector<IMonitorModule *>	_data;
		int					_n;
		SDL_Renderer		*_ren;
		int					_posX;
		int					_posY;
		int					_sizeH;
		int					_sizeW;
		std::array<int, 100>	_mon1;
		std::array<int, 100>	_mon2;
		SDL_Texture			*_line1;
		SDL_Texture			*_line2;
		SDL_Texture			*_back;
		TTF_Font			*_font;
		btn					_btn1;
		btn					_btn2;
		std::string const	&_top;
};

#endif
