/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:46:08 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 18:14:34 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAMModule.hpp"

RAMModule::RAMModule(void) : _top(*(new std::string))
{
}

RAMModule::RAMModule(std::string const & top) : _top(top)
{
}

RAMModule::RAMModule(RAMModule const & src) : _top(src._top)
{
	*this = src;
}

RAMModule::~RAMModule(void)
{
}

RAMModule			&RAMModule::operator=(RAMModule const & src)
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

void				RAMModule::update(void)
{
	this->_title = "RAM";
	this->_text1 = "Used: " + this->_top.substr(_top.find("PhysMem:") + 9, 10);
	this->_text1 = this->_text1.substr(0, this->_text1.find("M") + 1);
	int mem1 = atoi(this->_text1.c_str() + 6);

	this->_text2 = "Unused: " + this->_top.substr(_top.find(" wired),") + 9, 10);
	this->_text2 = this->_text2.substr(0, this->_text2.find("M") + 1);
	int mem2 = atoi(this->_text2.c_str() + 8);

	this->_data1 = mem1 / ((mem1 + mem2) / 100);
	this->_data2 = mem2 / ((mem1 + mem2) / 100);
}

int					RAMModule::getData1(void)
{
	return (this->_data1);
}

int					RAMModule::getData2(void)
{
	return (this->_data2);
}


std::string			RAMModule::getTitle(void)
{
	return (this->_title);
}


std::string			RAMModule::getText1(void)
{
	return (this->_text1);
}

std::string			RAMModule::getText2(void)
{
	return (this->_text2);
}
