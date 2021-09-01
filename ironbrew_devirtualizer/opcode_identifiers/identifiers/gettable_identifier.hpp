#pragma once

#include "../identifier_handler.hpp"

namespace deobf::ironbrew_devirtualizer::opcode_identifiers {
	using namespace ast;

	struct gettable_identifier final : public basic_opcode_handler {
		vm_arch::opcode handle(ir::statement::block* path) override {
			if (path->body.size() == 1) {
				if (auto assign = path->body.at(0)->as<ir::statement::variable_assign>()) {
					const auto assign_string = assign->to_string();
					if (assign_string == "stack[instruction_opcode_a] = stack[instruction_opcode_b][instruction_opcode_c]" 
						|| assign_string == "stack[instruction_opcode_a] = stack[instruction_opcode_b][stack[instruction_opcode_c]]") {
						std::cout << "gettable\n";
						return vm_arch::opcode::op_gettable;
					}
				}
			}

			return __super::handle(path);
		}
	};
}