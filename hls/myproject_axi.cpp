#include "firmware/myproject.h"
#include "ap_int.h"
#include "ap_fixed.h"

typedef ap_fixed<16,6> in_t;
typedef ap_fixed<36,16> out_t;

// Wrapper simples para uso com AXI-Lite
void myproject_axi(
    ap_int<16> x0_bits,
    ap_int<16> x1_bits,
    ap_int<16> x2_bits,
    ap_int<16> x3_bits,
    ap_uint<2> &pred_class
) {
#pragma HLS INTERFACE s_axilite port=x0_bits bundle=CTRL
#pragma HLS INTERFACE s_axilite port=x1_bits bundle=CTRL
#pragma HLS INTERFACE s_axilite port=x2_bits bundle=CTRL
#pragma HLS INTERFACE s_axilite port=x3_bits bundle=CTRL
#pragma HLS INTERFACE s_axilite port=pred_class bundle=CTRL
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL

    in_t in[4];
#pragma HLS ARRAY_PARTITION variable=in complete

    out_t out[3];
#pragma HLS ARRAY_PARTITION variable=out complete

    in[0].range(15,0) = x0_bits.range(15,0);
    in[1].range(15,0) = x1_bits.range(15,0);
    in[2].range(15,0) = x2_bits.range(15,0);
    in[3].range(15,0) = x3_bits.range(15,0);

    myproject(in, out);

    // argmax dos 3 logits
    ap_uint<2> cls = 0;
    if (out[1] > out[0]) cls = 1;
    if (out[2] > out[cls]) cls = 2;

    pred_class = cls;
}
