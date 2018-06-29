/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:47:56 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 16:12:07 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAINMODULE_HPP
# define MAINMODULE_HPP
# include "IMonitorModule.hpp"
# include <iostream>

class					MainModule : public IMonitorModule
{
	public:
		MainModule(void);
		MainModule(MainModule const & src);
		MainModule		&operator=(MainModule const & src);
		~MainModule(void);
		void			update(void);
		void			updateHostname(void);
		void			updateUsername(void);
		void			updateOSinfo(void);
		void			updateDate(void);
		int				getData1(void);
		int				getData2(void);
		std::string		getTitle(void);
		std::string		getText1(void);
		std::string		getText2(void);
	private:
		std::string		_title;
		std::string		_text1;
		std::string		_text2;
		int				_data1;
		int				_data2;
};

#endif
