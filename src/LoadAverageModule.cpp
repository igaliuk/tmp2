/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LoadAverageModule.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:46:08 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 18:47:40 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LoadAverageModule.hpp"

LoadAverageModule::LoadAverageModule(void) : _top(*(new std::string))
{
}

LoadAverageModule::LoadAverageModule(std::string const & top) : _top(top)
{
}

LoadAverageModule::LoadAverageModule(LoadAverageModule const & src) : _top(src._top)
{
	*this = src;
}

LoadAverageModule::~LoadAverageModule(void)
{
}

LoadAverageModule			&LoadAverageModule::operator=(LoadAverageModule const & src)
{
	if (this != &src)
	{
		this->_title = src._title;
		this->_data1 = src._data1;
		this->_data2 = src._data2;
		this->_text1 = src._text1;
		this->_text2 = src._text2;
	}
	return (*this);
}

void				LoadAverageModule::update(void)
{
	this->_title = "LoadAverage";
	this->_text1 = "Last minute: " + this->_top.substr(_top.find("Load Avg: ") + 10, 4);
	this->_data1 = atoi(this->_text1.c_str() + 13) * 10 + atoi(this->_text1.c_str() + 15) / 10;

	this->_text2 = "Last five minutes: " + this->_top.substr(_top.find("Load Avg: ") + 16, 4);
	this->_data2 = atoi(this->_text2.c_str() + 19) * 10 + atoi(this->_text2.c_str() + 21) / 10;
}

int					LoadAverageModule::getData1(void)
{
	return (this->_data1);
}

int					LoadAverageModule::getData2(void)
{
	return (this->_data2);
}


std::string			LoadAverageModule::getTitle(void)
{
	return (this->_title);
}


std::string			LoadAverageModule::getText1(void)
{
	return (this->_text1);
}

std::string			LoadAverageModule::getText2(void)
{
	return (this->_text2);
}
