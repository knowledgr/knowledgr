#pragma once
#include <colab/protocol/types.hpp>
#include <colab/protocol/config.hpp>

namespace colab { namespace protocol {	

   struct discipline
   {
	   //Science Technology Engineering Mathematics
	   enum discipline_category {
		   unknown,
		   science,
		   technology,
		   engineering,
		   mathematics
	   };

      discipline( discipline_category _c = unknown, uint32_t _r = 1 ) : category(_c), level(_r){}

	  discipline_category category;
	  uint32_t level;

	  static discipline::discipline_category category_from_str(const std::string& str);
      std::string category_str()const;

      static discipline from_string( const std::string& from );
      std::string       to_string()const;
   };
   
} } // colab::protocol

namespace fc {

    inline void to_variant( const colab::protocol::discipline& var,  fc::variant& vo ) { vo = var.to_string(); }
    inline void from_variant( const fc::variant& var,  colab::protocol::discipline& vo ) { vo = colab::protocol::discipline::from_string( var.as_string() ); }
}

FC_REFLECT( colab::protocol::discipline, (category)(level) )//~~~~~NLG~~~~~