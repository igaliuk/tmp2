/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProcessesModule.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:46:08 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 18:40:24 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProcessesModule.hpp"

ProcessesModule::ProcessesModule(void) : _top(*(new std::string))
{
}

ProcessesModule::ProcessesModule(std::string const & top) : _top(top)
{
}

ProcessesModule::ProcessesModule(ProcessesModule const & src) : _top(src._top)
{
	*this = src;
}

ProcessesModule::~ProcessesModule(void)
{
}

ProcessesModule			&ProcessesModule::operator=(ProcessesModule const & src)
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

void				ProcessesModule::update(void)
{
	this->_title = "Processes";
	this->_text1 = "Total: " + this->_top.substr(_top.find("Processes: ") + 11, 10);
	this->_text1 = this->_text1.substr(0, this->_text1.find(" t"));
	this->_data2 = atoi(this->_text1.c_str() + 7) / 50;
	if (this->_data2 > 100)
		this->_data2 = 100;

	this->_text2 = "Threads: " + this->_top.substr(_top.find(" sleeping, ") + 11, 10);
	this->_text2 = this->_text2.substr(0, this->_text2.find(" t"));
	this->_data1 = atoi(this->_text2.c_str() + 9) / 50;
	if (this->_data1 > 100)
		this->_data1 = 100;
}

int					ProcessesModule::getData1(void)
{
	return (this->_data1);
}

int					ProcessesModule::getData2(void)
{
	return (this->_data2);
}


std::string			ProcessesModule::getTitle(void)
{
	return (this->_title);
}


std::string			ProcessesModule::getText1(void)
{
	return (this->_text1);
}

std::string			ProcessesModule::getText2(void)
{
	return (this->_text2);
}
