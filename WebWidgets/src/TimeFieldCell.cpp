//
// TimeFieldCell.cpp
//
// $Id: //poco/Main/WebWidgets/src/TimeFieldCell.cpp#2 $
//
// Library: WebWidgets
// Package: Controls
// Module:  TimeFieldCell
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "Poco/WebWidgets/TimeFieldCell.h"
#include "Poco/WebWidgets/DateFormatter.h"


namespace Poco {
namespace WebWidgets {


TimeFieldCell::TimeFieldCell(View* pOwner):
	TextFieldCell(pOwner, typeid(TimeFieldCell)),
	_format("%h:%M %A"),
	_fmt(TimeField::FMT_AMPM)
{
	setFormatter(new DateFormatter(_format));
}


TimeFieldCell::~TimeFieldCell()
{
}



void TimeFieldCell::setFormat(TimeField::Format fmt)
{
	if (_fmt != fmt)
	{
		_fmt = fmt;
		if (_fmt == TimeField::FMT_AMPM)
			_format = "%h:%M %A";
		else if (_fmt == TimeField::FMT_24H)
			_format = "%H:%M";
		else if (_fmt == TimeField::FMT_AMPM_WITHSECONDS)
			_format = "%h:%M:%S %A";
		else if (_fmt == TimeField::FMT_24H_WITHSECONDS)
			_format = "%H:%M:%S";
		else if (_fmt ==  TimeField::FMT_12H)
			_format = "%H:%M";
		setFormatter(new DateFormatter(_format));	
	}
}


} } // namespace Poco::WebWidgets
