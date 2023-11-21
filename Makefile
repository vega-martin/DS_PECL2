.PHONY: clean All

All:
	@echo "----------Building project:[ DS_PECL2 - Debug ]----------"
	@cd "DS_PECL2" && "$(MAKE)" -f  "DS_PECL2.mk"
clean:
	@echo "----------Cleaning project:[ DS_PECL2 - Debug ]----------"
	@cd "DS_PECL2" && "$(MAKE)" -f  "DS_PECL2.mk" clean
