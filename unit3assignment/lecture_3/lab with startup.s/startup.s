/* startup_cortex_m3.s
ENG: Mohamed Osman
*/

/* SRam = 0x20000000  */

.section .vectors

.word	0x20001000
.word	vector_handler       /*  1  resrt  */
.word	vector_handler       /*  2  NMI  */
.word	vector_handler       /*  3  hard fault  */
.word	vector_handler       /*  4  NM fault  */
.word	vector_handler       /*  5  Bus fault  */


.section .text

_reset:
	bl main
	b .

.thumb_func

vector_handler:
	b _reset




