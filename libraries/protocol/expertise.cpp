#include <knowledgr/protocol/expertise.hpp>
#include <boost/rational.hpp>
#include <boost/multiprecision/cpp_int.hpp>

/*


*/

namespace knowledgr { namespace protocol {

	static std::map<protocol::expertise_category, std::string> category_str_map;

	void expertise::set_expertise_category_str_map() {
		category_str_map[expctgry_unknown					] = "unknown";
		category_str_map[expctgry_logic						] = "Logic";
		category_str_map[expctgry_mathematics				] = "Mathematics";
		category_str_map[expctgry_astronomy_and_astrophysics] = "Astronomy and Astrophysics";
		category_str_map[expctgry_physics					] = "Physics";
		category_str_map[expctgry_chemistry					] = "Chemistry";
		category_str_map[expctgry_life_sciences				] = "Life Sciences";
		category_str_map[expctgry_earth_and_space_sciences	] = "Earth and Space Sciences";
		category_str_map[expctgry_agricultural_sciences		] = "Agricultural Sciences";
		category_str_map[expctgry_medical_sciences			] = "Medical Sciences";
		category_str_map[expctgry_technological_sciences	] = "Technological Sciences";
		category_str_map[expctgry_anthropology				] = "Anthropology";
		category_str_map[expctgry_demographics				] = "Demographics";
		category_str_map[expctgry_economic_sciences			] = "Economic Sciences";
		category_str_map[expctgry_geography					] = "Geography";
		category_str_map[expctgry_history 					] = "History";
		category_str_map[expctgry_juridical_sciences_and_law] = "Juridical Sciences and Law";
		category_str_map[expctgry_linguistics				] = "Linguistics";
		category_str_map[expctgry_pedagogy					] = "Pedagogy";
		category_str_map[expctgry_political_science			] = "Political Science";
		category_str_map[expctgry_psychology				] = "Psychology";
		category_str_map[expctgry_science_of_arts_and_letters]= "Science of Arts and Letters";
		category_str_map[expctgry_sociology					] = "Sociology";
		category_str_map[expctgry_ethics					] = "Ethics";
		category_str_map[expctgry_philosophy				] = "Philosophy";
	}

	std::string expertise::category_str()const
	{
		if (category_str_map.size() <= 0) {
			set_expertise_category_str_map();
		}

		if ( category >= expctgry_unknown && category <= expctgry_philosophy ) return category_str_map[category];
		return "unknown";
	}

	std::string expertise::category_str(protocol::expertise_category _c)
	{
		if (category_str_map.size() <= 0) {
			set_expertise_category_str_map();
		}

		if ( _c >= expctgry_unknown && _c <= expctgry_philosophy ) return category_str_map[_c];
		return "unknown";
	}

	expertise_category expertise::category_from_string(const std::string& str)
	{
		if (category_str_map.size() <= 0) {
			set_expertise_category_str_map();
		}

		std::string _str = fc::to_lower(fc::trim(str));
		for (map<expertise_category, std::string>::const_iterator i1 = category_str_map.begin(); i1 != category_str_map.end(); i1 ++) {
			std::string cmp_str = fc::to_lower((*i1).second);
			if (cmp_str == _str) {
				return (*i1).first;
			}
		}
		return expctgry_unknown;
	}

	vector<expertise_category> expertise::category_array_from_string(const std::string& str)
	{
		vector<std::string> str_array;
		std::string s = fc::trim(str);
		size_t dot_pos = s.find("|");

		if (dot_pos == std::string::npos ) {
			s = fc::trim(s);
			if (s != "") {
				str_array.push_back(s);
			}
		} else {
			while( dot_pos != std::string::npos )
			{
				auto lpart = s.substr( 0, dot_pos );
				auto rpart = s.substr( dot_pos + 1, s.length() - dot_pos- 1 );
				lpart = fc::trim(lpart);
				if (lpart != "") {
					str_array.push_back(lpart);
				}
				s = fc::trim(rpart);
				dot_pos = s.find("|");
			}
		}
		vector<expertise_category> result;
		for (auto & s0 : str_array) {
			expertise_category expctgry = expertise::category_from_string(s0);
			if (expctgry != protocol::expctgry_unknown) {
				result.push_back(expctgry);
			}
		}
		return result;
	}

	std::string expertise::to_string()const
	{
		std::string result = category_str();
		char s[100];
		result += " : ";
		sprintf(s, "%d", level);
		result += s;
		return result;
	}

	expertise expertise::from_string( const std::string& from )
	{
		try
		{
			string s = fc::trim( from );
			auto dot_pos = s.find( ":" );
			expertise result;
			if( dot_pos != std::string::npos )
			{
				auto cpart = s.substr( 0, dot_pos );
				auto rpart = s.substr( dot_pos + 1, s.length() - dot_pos- 1 );
				result.category = expertise::category_from_string(cpart);
				
				sscanf(rpart.c_str(), "%d", &result.level);
			}

			return result;
		}
		FC_CAPTURE_AND_RETHROW( (from) )
	}

	bool operator == ( const expertise& a, const expertise& b )
	{
		return ( a.category == b.category ) &&
					( a.level  == b.level );
	}
} } // knowledgr::protocol
