#pragma once

#include "../../../vm_arch/proto.hpp"

#include <string_view>
#include <cstdlib>
#include <unordered_set>
#include <iostream>
#include <unordered_map>
#include <algorithm>

#include <sstream>

#include "deserializer_context.hpp"

// todo fix data loss when converting to integeral types

namespace deobf::ironbrew_devirtualizer {
	namespace symbolic_execution::deserializer {
		struct deserializer_emulator_main;
		
		class deserializer_helper final {
		private:
			friend struct symbolic_execution::deserializer::deserializer_emulator_main;

			static constexpr std::size_t int_size = 4;
			static constexpr std::size_t sizet_size = 4;

			const unsigned char vm_xor_key;

			const inline bool get_bits(std::size_t number, std::size_t i) const;
			const inline std::size_t get_bits(std::size_t number, std::size_t i, std::size_t j) const;

			//static const std::string decompress_vm_string(std::string_view vm_string);

			std::istringstream managed_deserializer_string;
		public:
			deserializer_helper(deserializer_helper&&) = default;

			explicit deserializer_helper(const std::string& vm_string, const unsigned char xor_key) : managed_deserializer_string{ vm_string }, vm_xor_key(xor_key) { };


			// utilities
			const std::uint8_t get_8_bits();
			const std::uint16_t get_16_bits();
			const std::uint32_t get_32_bits();
			const double get_float();

			const std::string get_string(std::size_t length);
			const std::string get_string();

			//[[deprecated]] std::unique_ptr<vm_arch::proto> deserialize(deserializer_context* ctx);
		};
	}
}