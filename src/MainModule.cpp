/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:48:46 by anestor           #+#    #+#             */
/*   Updated: 2018/04/15 16:16:41 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MainModule.hpp"

MainModule::MainModule(void)
{
	this->_data1 = 0;
	this->_data2 = 0;
	this->_title = " ";
	this->_text1 = " ";
	this->_text2 = " ";
}

MainModule::MainModule(MainModule const & src)
{
	*this = src;
}

MainModule::~MainModule(void)
{
}

MainModule			&MainModule::operator=(MainModule const & src)
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

void				MainModule::updateDate(void)
{
	char		buffer[32];
	std::string	output;
	FILE		*stream = popen("/bin/date", "r");
	if (stream)
	{
		while (!feof(stream))
            if (fgets(buffer, 32, stream) != NULL) output.append(buffer);
        pclose(stream);
    }
	this->_text2 = output.substr(0, output.size() - 1);
}

void				MainModule::updateUsername(void)
{
	char		buffer[32];
	std::string	output;
	FILE		*stream = popen("/usr/bin/id -un", "r");
	if (stream)
	{
		while (!feof(stream))
            if (fgets(buffer, 32, stream) != NULL) output.append(buffer);
        pclose(stream);
    }
	this->_text1.append(" / ");
	this->_text1.append(output.substr(0, output.size() - 1));
}

void				MainModule::updateHostname(void)
{
	char		buffer[32];
	std::string	output;
	FILE		*stream = popen("/bin/hostname", "r");
	if (stream)
	{
		while (!feof(stream))
            if (fgets(buffer, 32, stream) != NULL) output.append(buffer);
        pclose(stream);
    }
	this->_text1 = output.substr(0, output.size() - 1);
}

void				MainModule::updateOSinfo(void)
{
	char		buffer[32];
	std::string	output;
	FILE		*stream = popen("/usr/bin/sw_vers", "r");
	if (stream)
	{
		while (!feof(stream))
            if (fgets(buffer, 32, stream) != NULL) output.append(buffer);
        pclose(stream);
    }
	this->_title = output.substr(13, 8);
	this->_title.append(" / ");
	this->_title.append(output.substr(38, 7));
	this->_title.append(" / ");
	this->_title.append(output.substr(60, 5));
}

void				MainModule::update(void)
{
	if (this->_title == " ")
		this->updateOSinfo();
	if (this->_text1 == " ")
	{
		this->updateHostname();
		this->updateUsername();
	}
	this->updateDate();
}

int					MainModule::getData1(void)
{
	return (this->_data1);
}

int					MainModule::getData2(void)
{
	return (this->_data2);
}


std::string			MainModule::getTitle(void)
{
	return (this->_title);
}


std::string			MainModule::getText1(void)
{
	return (this->_text1);
}

std::string			MainModule::getText2(void)
{
	return (this->_text2);
}
