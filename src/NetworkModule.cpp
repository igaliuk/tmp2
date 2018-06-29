/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:46:08 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 18:53:04 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.hpp"

NetworkModule::NetworkModule(void) : _top(*(new std::string))
{
}

NetworkModule::NetworkModule(std::string const & top) : _top(top)
{
}

NetworkModule::NetworkModule(NetworkModule const & src) : _top(src._top)
{
	*this = src;
}

NetworkModule::~NetworkModule(void)
{
}

NetworkModule			&NetworkModule::operator=(NetworkModule const & src)
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

void				NetworkModule::update(void)
{
	this->_title = "Network";
	this->_text1 = "Packets in: " + this->_top.substr(_top.find("Networks: packets:") + 19, 10);
	this->_text1 = this->_text1.substr(0, this->_text1.find("/"));

	this->_data1 = atoi(this->_text1.c_str() + 12) / 100000;
	if (this->_data1 > 100)
		this->_data1 = 100;

	this->_text2 = "Packets out: " + this->_top.substr(_top.find(" in, ") + 5, 10);
	this->_text2 = this->_text2.substr(0, this->_text2.find("/"));

	this->_data2 = atoi(this->_text2.c_str() + 13) / 100000;;
	if (this->_data2 > 100)
		this->_data2 = 100;
}

int					NetworkModule::getData1(void)
{
	return (this->_data1);
}

int					NetworkModule::getData2(void)
{
	return (this->_data2);
}


std::string			NetworkModule::getTitle(void)
{
	return (this->_title);
}


std::string			NetworkModule::getText1(void)
{
	return (this->_text1);
}

std::string			NetworkModule::getText2(void)
{
	return (this->_text2);
}
