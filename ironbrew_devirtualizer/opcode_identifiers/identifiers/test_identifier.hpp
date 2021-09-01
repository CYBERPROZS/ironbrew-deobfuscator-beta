#pragma once

#include "../identifier_handler.hpp"

namespace deobf::ironbrew_devirtualizer::opcode_identifiers {
	using namespace ast;

	struct test_identifier final : public basic_opcode_handler {
		vm_arch::opcode handle(ir::statement::block* path) override {
			if (path->body.size() == 1) {
				if (auto test_statement = path->find_first_of<ir::statement::if_statement>()) {
					auto condition = test_statement.value().get().condition->to_string();
					if (condition == "stack[instruction_opcode_a]" || condition == "not( stack[instruction_opcode_a] )") {
						return vm_arch::opcode::op_test;
					}
				}
			}

			return __super::handle(path);
		}
	};
}