/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:43:27 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 17:00:48 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP
# include "IMonitorModule.hpp"
# include <iostream>

class					NetworkModule : public IMonitorModule
{
	public:
		NetworkModule(std::string const  & top);
		NetworkModule(NetworkModule const & src);
		NetworkModule		&operator=(NetworkModule const & src);
		~NetworkModule(void);
		void			update(void);
		int				getData1(void);
		int				getData2(void);
		std::string		getTitle(void);
		std::string		getText1(void);
		std::string		getText2(void);
	private:
		NetworkModule(void);
		std::string		_title;
		std::string		_text1;
		std::string		_text2;
		int				_data1;
		int				_data2;
		std::string const	&_top;
};

#endif
