/*
 * Xournal++
 *
 * Prints a Stacktrace
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "StringUtils.h"

#include <iostream>

class Stacktrace
{
private:
	Stacktrace();
	virtual ~Stacktrace();

public:
	static void setExename(string name);

	static void printStracktrace();
	static void printStracktrace(std::ostream& stream);
};
