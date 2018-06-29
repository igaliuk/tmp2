/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 19:01:43 by anestor           #+#    #+#             */
/*   Updated: 2018/04/14 19:05:35 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP
# include <iostream>

class						IMonitorModule
{
	public:
		virtual	~IMonitorModule(void) {};
		virtual void		update(void) = 0;
		virtual	int			getData1(void) = 0;
		virtual int			getData2(void) = 0;
		virtual std::string	getTitle(void) = 0;
		virtual std::string	getText1(void) = 0;
		virtual std::string getText2(void) = 0;
};

#endif
