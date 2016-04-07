#ifndef _ADTEXCEPTION_HPP
#define _ADTEXCEPTION_HPP
#include <stdlib.h>
#include <stdexcept>
#include <string.h>
using namespace std;
//! @author Ferdi Stoeltie 1665045
//! @brief All ADT exceptions inherit from this base class.
//! @date 07-04-2016
class ADTException : public invalid_argument
{
public:
	//!	@brief Adds a given Duration to the current Moment and returns a new Moment
	//!	@param [in] refDuration uses this Duration to add (positive values only!)
	//!	@return new Moment that is the result of adding a given Duration from current Moment
	ADTException(string specific_error, string class_error) : 
	/*specific_error{specific_error}, class_error{class_error},*/ invalid_argument{"test"} 
	{}
	/*virtual const char* what() const throw()
	{
		return (base_error + class_error + " " + specific_error).c_str();
	}

protected:
	const string specific_error;
	const string class_error;
private:
	const string base_error = "ADT exception: ";*/
};
#endif