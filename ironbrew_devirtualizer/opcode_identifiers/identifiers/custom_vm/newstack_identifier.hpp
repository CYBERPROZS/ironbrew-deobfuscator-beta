#pragma once

#include "../../identifier_handler.hpp"

// used for control flow obfuscation

namespace deobf::ironbrew_devirtualizer::opcode_identifiers {
	using namespace ast;

	struct newstack_identifier final : public basic_opcode_handler {
		vm_arch::opcode handle(ir::statement::block* path) override {
			if (path->body.size() == 2 && path->body.at(0)->is<ir::statement::variable_assign>()) {
				const auto assign_string = path->body.at(0)->to_string();
				if (assign_string == "stack = { }") {
					return vm_arch::opcode::op_newstack;
				}
			}

			return __super::handle(path);
		}
	};
}