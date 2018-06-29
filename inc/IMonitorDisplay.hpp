/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:35:43 by anestor           #+#    #+#             */
/*   Updated: 2018/04/14 22:55:26 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP
# include "SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"

struct							btn
{
	SDL_Texture					*texOn;
	SDL_Texture					*texOff;
	SDL_Rect					rect;
	bool						active;
};

class							IMonitorDisplay
{
	public:
		virtual ~IMonitorDisplay(void) {};
		virtual void			render(void) = 0;
		virtual void			setPosY(int posY) = 0;
		virtual int				getH(void) = 0;
		virtual int 			getW(void) = 0;
		virtual void			renderTitle(void) = 0;
		virtual void			renderText1(void) = 0;
		virtual void			renderText2(void) = 0;
		virtual void			renderButtons(void) = 0;
		virtual bool			getBtn1(void) = 0;
		virtual bool			getBtn2(void) = 0;
		virtual void			btn1Active(void) = 0;
		virtual void			btn2Active(void) = 0;
		virtual SDL_Rect		getBtn1Rect(void) = 0;
		virtual SDL_Rect		getBtn2Rect(void) = 0;
		virtual void			nextModule(void) = 0;
		virtual void			prevModule(void) = 0;
};

#endif
