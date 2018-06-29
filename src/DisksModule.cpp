/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisksModule.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:14:54 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 18:53:06 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DisksModule.hpp"

DisksModule::DisksModule(void) : _top(*(new std::string))
{
}

DisksModule::DisksModule(std::string const & top) : _top(top)
{
}

DisksModule::DisksModule(DisksModule const & src) : _top(src._top)
{
	*this = src;
}

DisksModule::~DisksModule(void)
{
}

DisksModule			&DisksModule::operator=(DisksModule const & src)
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

void				DisksModule::update(void)
{
	this->_title = "Disks";
	this->_text1 = "Read: " + this->_top.substr(_top.find("Disks: ") + 7, 10);
	this->_text1 = this->_text1.substr(0, this->_text1.find("/"));

	this->_data1 = atoi(this->_text1.c_str() + 6) / 10000;
	if (this->_data1 > 100)
		this->_data1 = 100;

	this->_text2 = "Write: " + this->_top.substr(_top.find(" read, ") + 7, 10);
	this->_text2 = this->_text2.substr(0, this->_text2.find("/"));

	this->_data2 = atoi(this->_text2.c_str() + 7) / 10000;
	if (this->_data2 > 100)
		this->_data2 = 100;
}

int					DisksModule::getData1(void)
{
	return (this->_data1);
}

int					DisksModule::getData2(void)
{
	return (this->_data2);
}


std::string			DisksModule::getTitle(void)
{
	return (this->_title);
}


std::string			DisksModule::getText1(void)
{
	return (this->_text1);
}

std::string			DisksModule::getText2(void)
{
	return (this->_text2);
}
