/*
* =====================================================================================
*
*       Filename:  kmer.h
*
*    Description:
*
*        Version:  1.0
*        Created:  04/18/2016 05:06:51 PM
*       Revision:  none
*       Compiler:  gcc
*
*         Author:  Prashant Pandey (ppandey@cs.stonybrook.edu)
*                  Rob Patro (rob.patro@cs.stonybrook.edu)
*                  Rob Johnson (rob@cs.stonybrook.edu)
*   Organization:  Stony Brook University
*
* =====================================================================================
*/

#ifndef _KMER_H_
#define _KMER_H_

#include <stdio.h>
#include <string>

enum DNA_MAP {A, C, T, G};  // A=1, C=0, T=2, G=3
static uint8_t DNA_REVERSE[]={2,3,0,1};
#define BITMASK(nbits) ((nbits) == 64 ? 0xffffffffffffffff : (1ULL << (nbits)) \
												- 1ULL)
using namespace std;



class kmer {
public:
	static inline char map_int(uint8_t base);
	static inline uint8_t map_base(char base);
	static uint64_t str_to_int(string str);
	static uint64_t str_to_canonical_int(string str);
	static string canonicalKmer(string k);
	static string int_to_str(uint64_t kmer, uint32_t K);
	static inline int reverse_complement_base(int x);
	static uint64_t reverse_complement(uint64_t kmer, uint32_t K);
	static inline bool compare_kmers(uint64_t kmer, uint64_t kmer_rev);
	static inline unsigned __int128 word_reverse_complement(unsigned __int128 w);
	static inline int64_t word_reverse_complement(uint64_t w);
	static inline uint32_t word_reverse_complement(uint32_t w);

private:
	kmer();
};

/*return the integer representation of the base */
inline char kmer::map_int(uint8_t base)
{
	switch(base) {
		case DNA_MAP::A: { return 'A'; }
		case DNA_MAP::T: { return 'T'; }
		case DNA_MAP::C: { return 'C'; }
		case DNA_MAP::G: { return 'G'; }
		default:  { return DNA_MAP::G+1; }
	}
}

/*return the integer representation of the base */
inline uint8_t kmer::map_base(char base)
{
	switch(base) {
		case 'A': { return DNA_MAP::A; }
		case 'T': { return DNA_MAP::T; }
		case 'C': { return DNA_MAP::C; }
		case 'G': { return DNA_MAP::G; }
		default:  { return DNA_MAP::G+1; }
	}
}



/* Return the reverse complement of a base */
inline int kmer::reverse_complement_base(int x) { return DNA_REVERSE[x]; }


/* Compare the kmer and its reverse complement and return the result
* Return true if the kmer is greater than or equal to its
* reverse complement.
* */
inline bool kmer::compare_kmers(uint64_t kmer, uint64_t kmer_rev)
{
	return kmer <= kmer_rev;
}



#endif
