/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LoadAverageModule.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:43:27 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 18:07:32 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADAVERAGEMODULE_HPP
# define LOADAVERAGEMODULE_HPP
# include "IMonitorModule.hpp"
# include <iostream>

class					LoadAverageModule : public IMonitorModule
{
	public:
		LoadAverageModule(std::string const  & top);
		LoadAverageModule(LoadAverageModule const & src);
		LoadAverageModule		&operator=(LoadAverageModule const & src);
		~LoadAverageModule(void);
		void			update(void);
		int				getData1(void);
		int				getData2(void);
		std::string		getTitle(void);
		std::string		getText1(void);
		std::string		getText2(void);
	private:
		LoadAverageModule(void);
		std::string		_title;
		std::string		_text1;
		std::string		_text2;
		int				_data1;
		int				_data2;
		std::string const	&_top;
};

#endif
