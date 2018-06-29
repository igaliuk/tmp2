/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:46:08 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 18:26:37 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUModule.hpp"

CPUModule::CPUModule(void) : _top(*(new std::string))
{
}

CPUModule::CPUModule(std::string const & top) : _top(top)
{
}

CPUModule::CPUModule(CPUModule const & src) : _top(src._top)
{
	*this = src;
}

CPUModule::~CPUModule(void)
{
}

CPUModule			&CPUModule::operator=(CPUModule const & src)
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

void				CPUModule::update(void)
{
	this->_title = "CPU";
	this->_text1 = "CPU usage: " + this->_top.substr(_top.find("CPU usage:") + 11, 7);
	this->_text1 = this->_text1.substr(0, this->_text1.find("%") + 1);
	this->_data1 = atoi(this->_text1.c_str() + 11);

	this->_text2 = "CPU user: " + this->_top.substr(_top.find("CPU usage:") + 23, 7);
	this->_text2 = this->_text2.substr(0, this->_text2.find("%") + 1);
	this->_data2 = atoi(this->_text2.c_str() + 10);
}

int					CPUModule::getData1(void)
{
	return (this->_data1);
}

int					CPUModule::getData2(void)
{
	return (this->_data2);
}


std::string			CPUModule::getTitle(void)
{
	return (this->_title);
}


std::string			CPUModule::getText1(void)
{
	return (this->_text1);
}

std::string			CPUModule::getText2(void)
{
	return (this->_text2);
}
