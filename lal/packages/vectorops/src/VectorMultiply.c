/**** <lalVerbatim file="VectorMultiplyCV">
 * Author: J. D. E. Creighton, T. D. Creighton, A. M. Sintes
 * $Id$
 **** </lalVerbatim> */

/**** <lalLaTeX>
 *
 * \subsection{Module \texttt{VectorMultiply.c}}
 *
 * Multiply two vectors.
 *
 * \subsubsection*{Prototypes}
 * \input{VectorMultiplyCP}
 * \idx{LALCCVectorMultiply()}
 * \idx{LALCCVectorMultiplyConjugate()}
 * \idx{LALCCVectorDivide()}
 * \idx{LALZZVectorMultiply()}
 * \idx{LALZZVectorMultiplyConjugate()}
 * \idx{LALZZVectorDivide()}
 * \idx{LALSCVectorMultiply()}
 * \idx{LALSSVectorMultiply()}
 * \idx{LALDZVectorMultiply()}
 * \idx{LALDDVectorMultiply()}
 * 
 * \subsubsection*{Description}
 *
 * Let \texttt{u}, \texttt{v}, and \texttt{w} be objects of type
 * \texttt{COMPLEX8Vector}, and let \texttt{a}, \texttt{b}, and \texttt{c} be
 * objects of type \texttt{REAL4Vector}.
 * 
 * The \verb:LALCCVectorMultiply( &status, &w, &u, &v ): function computes
 * $\mbox{\texttt{w.data[i]}}=\mbox{\texttt{u.data[i]}}\times\mbox{\texttt{v.data[i]}}$.
 * 
 * The \verb:LALCCVectorMultiplyConjugate( &status, &w, &u, &v ): function
 * computes
 * $\mbox{\texttt{w.data[i]}}=\mbox{\texttt{u.data[i]}}\times\mbox{\texttt{v.data[i]}}^\ast$.
 * 
 * The \verb:LALCCVectorDivide( &status, &w, &u, &v ): function computes
 * $\mbox{\texttt{w.data[i]}}=\mbox{\texttt{u.data[i]}}/\mbox{\texttt{v.data[i]}}$.
 * 
 * The \verb:LALSCVectorMultiply( &status, &w, &a, &v ): function computes
 * $\mbox{\texttt{w.data[i]}}=\mbox{\texttt{a.data[i]}}\times\mbox{\texttt{v.data[i]}}$.
 * 
 * The \verb:LALSSVectorMultiply( &status, &c, &a, &b ): function computes
 * $\mbox{\texttt{c.data[i]}}=\mbox{\texttt{a.data[i]}}\times\mbox{\texttt{b.data[i]}}$.
 * 
 * The double-precison multiply routines (with \verb:D: or \verb:Z: names)
 * work similarly.
 *  
 * \subsubsection*{Algorithm}
 * 
 * 
 * The algorithm for complex division is described in
 * Sec.~5.4 of Ref.~\cite{ptvf:1992}.  The formula used is:
 * \[
 * \frac{a + ib}{c + id} = \left\{
 * \begin{array}{ll}
 * \frac{[a + b(d/c)] + i[b - a(d/c)]}{c + d(d/c)} & |c| \ge |d| \\
 * \frac{[a(c/d) + b] + i[b(c/d) - a]}{c(c/d) + d} & |c| < |d|.
 * \end{array}
 * \right.
 * \]
 * 
 * \vfill{\footnotesize\input{VectorMultiplyCV}}
 * 
 **** </lalLaTeX> */ 




#include <math.h>
#include <lal/LALStdlib.h>
#include <lal/VectorOps.h>

NRCSID (VECTORMULTIPLYC, "$Id$");

/* <lalVerbatim file="VectorMultiplyCP"> */
void
LALCCVectorDivide (
    LALStatus            *status,
    COMPLEX8Vector       *out,
    const COMPLEX8Vector *in1,
    const COMPLEX8Vector *in2
    )
{ /* </lalVerbatim> */
  COMPLEX8 *a;
  COMPLEX8 *b;
  COMPLEX8 *c;
  INT4      n;

  INITSTATUS (status, "LALCCVectorDivide", VECTORMULTIPLYC);

  ASSERT (out, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (in2, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in2->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->length > 0, status, VECTOROPSH_ESIZE, VECTOROPSH_MSGESIZE);
  ASSERT (in1->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);
  ASSERT (in2->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);

  a = in1->data;
  b = in2->data;
  c = out->data;
  n = out->length;

  while (n-- > 0)
  {
    REAL4 ar = a->re;
    REAL4 ai = a->im;
    REAL4 br = b->re;
    REAL4 bi = b->im;

    if (fabs(br) > fabs(bi))
    {
      REAL4 ratio = bi/br;
      REAL4 denom = br + ratio*bi;

      c->re = (ar + ratio*ai)/denom;
      c->im = (ai - ratio*ar)/denom;
    }
    else
    {
      REAL4 ratio = br/bi;
      REAL4 denom = bi + ratio*br;

      c->re = (ar*ratio + ai)/denom;
      c->im = (ai*ratio - ar)/denom;
    }

    ++a;
    ++b;
    ++c;
  }

  RETURN (status);
}


/* <lalVerbatim file="VectorMultiplyCP"> */
void
LALZZVectorDivide (
    LALStatus             *status,
    COMPLEX16Vector       *out,
    const COMPLEX16Vector *in1,
    const COMPLEX16Vector *in2
    )
{ /* </lalVerbatim> */
  COMPLEX16 *a;
  COMPLEX16 *b;
  COMPLEX16 *c;
  INT4       n;

  INITSTATUS (status, "LALZZVectorDivide", VECTORMULTIPLYC);

  ASSERT (out, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (in2, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in2->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->length > 0, status, VECTOROPSH_ESIZE, VECTOROPSH_MSGESIZE);
  ASSERT (in1->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);
  ASSERT (in2->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);

  a = in1->data;
  b = in2->data;
  c = out->data;
  n = out->length;

  while (n-- > 0)
  {
    REAL8 ar = a->re;
    REAL8 ai = a->im;
    REAL8 br = b->re;
    REAL8 bi = b->im;

    if (fabs(br) > fabs(bi))
    {
      REAL8 ratio = bi/br;
      REAL8 denom = br + ratio*bi;

      c->re = (ar + ratio*ai)/denom;
      c->im = (ai - ratio*ar)/denom;
    }
    else
    {
      REAL8 ratio = br/bi;
      REAL8 denom = bi + ratio*br;

      c->re = (ar*ratio + ai)/denom;
      c->im = (ai*ratio - ar)/denom;
    }

    ++a;
    ++b;
    ++c;
  }

  RETURN (status);
}



/* <lalVerbatim file="VectorMultiplyCP"> */
void
LALCCVectorMultiply (
    LALStatus            *status,
    COMPLEX8Vector       *out,
    const COMPLEX8Vector *in1,
    const COMPLEX8Vector *in2
    )
{ /* </lalVerbatim> */
  COMPLEX8 *a;
  COMPLEX8 *b;
  COMPLEX8 *c;
  INT4      n;

  INITSTATUS (status, "LALCCVectorMultiply", VECTORMULTIPLYC);

  ASSERT (out, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (in2, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in2->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->length > 0, status, VECTOROPSH_ESIZE, VECTOROPSH_MSGESIZE);
  ASSERT (in1->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);
  ASSERT (in2->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);

  a = in1->data;
  b = in2->data;
  c = out->data;
  n = out->length;

  while (n-- > 0)
  {
    REAL4 ar = a->re;
    REAL4 ai = a->im;
    REAL4 br = b->re;
    REAL4 bi = b->im;

    c->re = ar*br - ai*bi;
    c->im = ar*bi + ai*br;

    ++a;
    ++b;
    ++c;
  }

  RETURN (status);
}


/* <lalVerbatim file="VectorMultiplyCP"> */
void
LALZZVectorMultiply (
    LALStatus             *status,
    COMPLEX16Vector       *out,
    const COMPLEX16Vector *in1,
    const COMPLEX16Vector *in2
    )
{ /* </lalVerbatim> */
  COMPLEX16 *a;
  COMPLEX16 *b;
  COMPLEX16 *c;
  INT4       n;

  INITSTATUS (status, "LALZZVectorMultiply", VECTORMULTIPLYC);

  ASSERT (out, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (in2, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in2->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->length > 0, status, VECTOROPSH_ESIZE, VECTOROPSH_MSGESIZE);
  ASSERT (in1->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);
  ASSERT (in2->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);

  a = in1->data;
  b = in2->data;
  c = out->data;
  n = out->length;

  while (n-- > 0)
  {
    REAL8 ar = a->re;
    REAL8 ai = a->im;
    REAL8 br = b->re;
    REAL8 bi = b->im;

    c->re = ar*br - ai*bi;
    c->im = ar*bi + ai*br;

    ++a;
    ++b;
    ++c;
  }

  RETURN (status);
}


/* <lalVerbatim file="VectorMultiplyCP"> */
void
LALCCVectorMultiplyConjugate (
    LALStatus            *status,
    COMPLEX8Vector       *out,
    const COMPLEX8Vector *in1,
    const COMPLEX8Vector *in2
    )
{ /* </lalVerbatim> */
  COMPLEX8 *a;
  COMPLEX8 *b;
  COMPLEX8 *c;
  INT4      n;

  INITSTATUS (status, "LALCCVectorMultiplyConjugate", VECTORMULTIPLYC);

  ASSERT (out, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (in2, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in2->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->length > 0, status, VECTOROPSH_ESIZE, VECTOROPSH_MSGESIZE);
  ASSERT (in1->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);
  ASSERT (in2->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);

  a = in1->data;
  b = in2->data;
  c = out->data;
  n = out->length;

  while (n-- > 0)
  {
    REAL4 ar = a->re;
    REAL4 ai = a->im;
    REAL4 br = b->re;
    REAL4 bi = b->im;

    c->re = ar*br + ai*bi;
    c->im = ai*br - ar*bi;

    ++a;
    ++b;
    ++c;
  }

  RETURN (status);
}


/* <lalVerbatim file="VectorMultiplyCP"> */
void
LALZZVectorMultiplyConjugate (
    LALStatus             *status,
    COMPLEX16Vector       *out,
    const COMPLEX16Vector *in1,
    const COMPLEX16Vector *in2
    )
{ /* </lalVerbatim> */
  COMPLEX16 *a;
  COMPLEX16 *b;
  COMPLEX16 *c;
  INT4       n;

  INITSTATUS (status, "LALZZVectorMultiplyConjugate", VECTORMULTIPLYC);

  ASSERT (out, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (in2, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in2->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->length > 0, status, VECTOROPSH_ESIZE, VECTOROPSH_MSGESIZE);
  ASSERT (in1->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);
  ASSERT (in2->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);

  a = in1->data;
  b = in2->data;
  c = out->data;
  n = out->length;

  while (n-- > 0)
  {
    REAL8 ar = a->re;
    REAL8 ai = a->im;
    REAL8 br = b->re;
    REAL8 bi = b->im;

    c->re = ar*br + ai*bi;
    c->im = ai*br - ar*bi;

    ++a;
    ++b;
    ++c;
  }

  RETURN (status);
}


/* <lalVerbatim file="VectorMultiplyCP"> */
void
LALSCVectorMultiply (
    LALStatus            *status,
    COMPLEX8Vector       *out,
    const REAL4Vector    *in1,
    const COMPLEX8Vector *in2
    )
{ /* </lalVerbatim> */
  REAL4    *a;
  COMPLEX8 *b;
  COMPLEX8 *c;
  INT4      n;

  INITSTATUS (status, "LALSCVectorMultiply", VECTORMULTIPLYC);

  ASSERT (out, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (in2, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in2->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->length > 0, status, VECTOROPSH_ESIZE, VECTOROPSH_MSGESIZE);
  ASSERT (in1->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);
  ASSERT (in2->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);

  a = in1->data;
  b = in2->data;
  c = out->data;
  n = out->length;

  while (n-- > 0)
  {
    REAL4 fac = *a;
    REAL4 br  = b->re;
    REAL4 bi  = b->im;

    c->re = fac*br;
    c->im = fac*bi;

    ++a;
    ++b;
    ++c;
  }

  RETURN (status);
}


/* <lalVerbatim file="VectorMultiplyCP"> */
void
LALDZVectorMultiply (
    LALStatus             *status,
    COMPLEX16Vector       *out,
    const REAL8Vector     *in1,
    const COMPLEX16Vector *in2
    )
{ /* </lalVerbatim> */
  REAL8     *a;
  COMPLEX16 *b;
  COMPLEX16 *c;
  INT4       n;

  INITSTATUS (status, "LALDZVectorMultiply", VECTORMULTIPLYC);

  ASSERT (out, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (in2, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in2->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->length > 0, status, VECTOROPSH_ESIZE, VECTOROPSH_MSGESIZE);
  ASSERT (in1->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);
  ASSERT (in2->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);

  a = in1->data;
  b = in2->data;
  c = out->data;
  n = out->length;

  while (n-- > 0)
  {
    REAL8 fac = *a;
    REAL8 br  = b->re;
    REAL8 bi  = b->im;

    c->re = fac*br;
    c->im = fac*bi;

    ++a;
    ++b;
    ++c;
  }

  RETURN (status);
}


/* <lalVerbatim file="VectorMultiplyCP"> */
void
LALSSVectorMultiply (
    LALStatus            *status,
    REAL4Vector          *out,
    const REAL4Vector    *in1,
    const REAL4Vector    *in2
    )
{ /* </lalVerbatim> */
  REAL4 *a;
  REAL4 *b;
  REAL4 *c;
  INT4   n;

  INITSTATUS (status, "LALSSVectorMultiply", VECTORMULTIPLYC);

  ASSERT (out, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (in2, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in2->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->length > 0, status, VECTOROPSH_ESIZE, VECTOROPSH_MSGESIZE);
  ASSERT (in1->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);
  ASSERT (in2->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);

  a = in1->data;
  b = in2->data;
  c = out->data;
  n = out->length;

  while (n-- > 0)
  {
    *c++ = (*a++)*(*b++);
  }

  RETURN (status);
}


/* <lalVerbatim file="VectorMultiplyCP"> */
void
LALDDVectorMultiply (
    LALStatus            *status,
    REAL8Vector          *out,
    const REAL8Vector    *in1,
    const REAL8Vector    *in2
    )
{ /* </lalVerbatim> */
  REAL8 *a;
  REAL8 *b;
  REAL8 *c;
  INT4   n;

  INITSTATUS (status, "LALDDVectorMultiply", VECTORMULTIPLYC);

  ASSERT (out, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (in2, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in1->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);
  ASSERT (in2->data, status, VECTOROPSH_ENULL, VECTOROPSH_MSGENULL);

  ASSERT (out->length > 0, status, VECTOROPSH_ESIZE, VECTOROPSH_MSGESIZE);
  ASSERT (in1->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);
  ASSERT (in2->length == out->length, status,
          VECTOROPSH_ESZMM, VECTOROPSH_MSGESZMM);

  a = in1->data;
  b = in2->data;
  c = out->data;
  n = out->length;

  while (n-- > 0)
  {
    *c++ = (*a++)*(*b++);
  }

  RETURN (status);
}

