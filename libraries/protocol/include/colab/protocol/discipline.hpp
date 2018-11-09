#pragma once
#include <colab/protocol/types.hpp>
#include <colab/protocol/config.hpp>

namespace colab { namespace protocol {	

	//Science Technology Engineering Mathematics
	typedef uint32_t discipline_category;
	const discipline_category unknown   = (0);
	const discipline_category science   = (1);
	const discipline_category technology= (2);
	const discipline_category engineering= (3);
	const discipline_category mathematics= (4);


   struct discipline
   {

      discipline( discipline_category _c = unknown, uint32_t _r = 1 ) : category(_c), level(_r){}

	  discipline_category category;
	  uint32_t level;

	  static discipline_category category_from_str(const std::string& str);
      std::string category_str()const;

      static discipline from_string( const std::string& from );
      std::string       to_string()const;
   };
   
} } // colab::protocol

namespace fc {

    inline void to_variant( const colab::protocol::discipline& var,  fc::variant& vo ) { vo = var.to_string(); }
    inline void from_variant( const fc::variant& var,  colab::protocol::discipline& vo ) { vo = colab::protocol::discipline::from_string( var.as_string() ); }
}

//FC_REFLECT_ENUM( colab::protocol::discipline_category, (unknown)(science)(technology)(engineering)(mathematics) )
FC_REFLECT( colab::protocol::discipline, (category)(level) )//~~~~~NLG~~~~~