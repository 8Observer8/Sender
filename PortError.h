#ifndef PORTERROR_H
#define PORTERROR_H

#include <string>
#include <stdexcept>

class PortError : public std::runtime_error {
public:

    PortError( const std::string &errorText ) : std::runtime_error( "" ) {
        m_message = "Error: " + errorText;
    }

    virtual ~PortError( ) throw( ) {

    }

    virtual const char *what( ) const throw( ) {
        return m_message.c_str( );
    }

private:
    std::string m_message;
};

#endif // PORTERROR_H
