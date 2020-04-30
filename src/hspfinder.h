#ifndef hspfinder_h
#define hspfinder_h

#include "alnparams.h"
#include "alnheuristics.h"
#include "chainer.h"
#include "seqinfo.h"
#include "hsp.h"

const unsigned MaxReps = 8;
const unsigned ANCLEN2 = 11;

class HSPFinder
	{
public:
	bool m_Nucleo;
	const AlnHeuristics *m_AH;
	const AlnParams *m_AP;
	const float *const *m_SubstMx;
	unsigned m_WordLength;
	unsigned m_WordCount;
	unsigned m_Hi;
	unsigned m_AlphaSize;
	byte *m_CharToLetter;

	const SeqInfo *m_SA;
	const SeqInfo *m_SB;

	unsigned *m_WordToPosA;
	unsigned *m_WordCountsA;

	unsigned *m_DiagToPosB;
	unsigned m_DiagToPosBSize;

	uint32 *m_WordsA;
	uint32 *m_WordsB;
	unsigned m_WordCountA;
	unsigned m_WordCountB;
	unsigned m_WordsASize;
	unsigned m_WordsBSize;

// HSPData memory is owned by m_Un/GappedHSPs.
// m_ChainedHSPs is a vector of pointers to
// memory owned by someone else.
	HSPData **m_UngappedHSPs;
	HSPData **m_GappedHSPs;
	HSPData **m_ChainedHSPs;
//	PathData **m_Paths;

	unsigned m_HSPSize;
	unsigned m_UngappedHSPCount;
	unsigned m_GappedHSPCount;
	unsigned m_ChainedHSPCount;

	Chainer m_Chainer;

public:
	HSPFinder();
	~HSPFinder();
	void Clear(bool ctor = false);

	void Init(const AlnParams &AP, const AlnHeuristics &AH);
	void SetA(SeqInfo *SI);
	void SetB(SeqInfo *SI);
	unsigned GetCommonWordCount() const;

	unsigned GetGlobalHSPs(unsigned MinLength, float MinFractId, bool StaggerOk,
	  float &HSPFractId);
	void UngappedBlast(float X, bool StaggerOk, unsigned MinLength = 0,
	  float MinScore = -1.0f);
	void UngappedBlast2Hit(float X, unsigned MinLength = 0,
	  float MinScore = -1.0f);
	unsigned GetAnchor2(unsigned PosA, unsigned PosB, unsigned L);
	void UngappedExtendLeft(unsigned PosA, unsigned PosB, float X, unsigned &Length,
	  float &Score);
	void UngappedExtendRight(unsigned PosA, unsigned PosB, float X, unsigned &Length,
	  float &Score);

	float ComputeMinUngappedRawScoreForGappedBlast() const;

	void AllocHSPCount(unsigned MaxHSPCount);

	const char *WordToStr(unsigned Word) const;
	void LogMe() const;
	unsigned SeqToWord(const byte *Seq) const;

	float ComputeGaplessHSPScore(const HSPData &HSP,
	  const float * const *SubstMx) const;

	static float GetAnchor(const HSPData &HSP, const byte *A, const byte *B,
	  const AlnParams &AP, unsigned &Loi, unsigned &Loj, unsigned &Len);

	void LogHSPs() const;
	void LogHSPsDot(HSPData **HSPs, unsigned HSPCount);

	void BlastOut(const HSPData *const *HSPs, unsigned HSPCount);
	void WriteHSP(FILE *f, const HSPData &HSP) const;
	void WriteHSP_ORF(FILE *f, const HSPData &HSP) const;
	void WriteHSPs(FILE *f, const vector<HSPData> &HSPs) const;
	void WriteHSPBlast6(const HSPData &HSP) const;

	unsigned SeqToWords(const byte *Seq, unsigned L, uint32 *Words) const;

	void AllocLA(unsigned LA);
	void AllocLB(unsigned LB);
	void AllocDiags(unsigned DiagCount);

	unsigned GetHSPIdCount(const HSPData &HSP) const;

	void Chain();

	static bool IsGlobalHSP(unsigned ALo, unsigned BLo, unsigned Length, unsigned LA, unsigned LB);
	static bool HSPInPath(const HSPData &HSP, const char *Path);
	};

#endif // hspfinder_h
