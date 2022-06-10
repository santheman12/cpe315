		mov		r0, #6  ;multiplicand
		mov		r1, #7 ;multiplier
		mov		r2, #0 ; result
		mov		r3, #1 ;mask
		mov		r4, #0 ;counter
		
		b		mult
		
mult
		str		lr, [sp, #-4]!
		str		r0, [sp, #-4]!
		str		r1, [sp, #-4]!
		str		r2, [sp, #-4]!
		str		r3, [sp, #-4]!
		str		r4, [sp, #-4]!
		
		cmp		r4, #31 ;compare the counter
		beq		exit ;if equal to 31, exit
		and		r5, r1, r3 ;get the Left most bit
		lsl		r3, r3, #1 ;shift the masker
		
		cmp		r5, #0 ;if the left most bit is 0
		beq		inc ; goto shift method
		add		r2, r2, r0 ;update product
		
inc
		lsl		r0, r0, #1 ;shift
		add		r4, r4, #1 ;increment the counter
		b		mult ;loop back to mult
		
exit
		
		
