/* splay, by Abreto<m@abreto.net>. */

#ifndef NULL
#define NULL 0
#endif

struct node
{
    node *f, *ch[2];
    int sz;
    node(node *fa = NULL, node *lc = NULL, node *rc = NULL)
    {
        f = fa;
        ch[0] = lc; ch[1] = rc;
        maintain();
    }
    inline int szof(const int d) const { return ch[d] ? ch[d]->sz : 0; }
    inline void maintain(void)
    {
        sz = szof(0) + szof(1) + 1;
    }
    inline int which(void)
    {
        if (NULL == f) return 0;
        return (f->ch[1] == this);  /* f[which()] == this */
    }
    inline node *setf(node *fa, int d = 0)
    {
        f = fa;
        if (f) { f->ch[d] = this; f->maintain(); }
        return f;
    }
    inline node *setc(node *son, int d = 0)
    {
        ch[d] = son;
        if (son) son->f = this;
        maintain();
        return this;
    }
    /* rotate this to its fater, return this. */
    inline node *rotate(void)
    {
        if (f != NULL)
        {
            node *ff = f->f;
            int d = which(), fd = ff ? f->which() : 0;
            setc(f->setc(ch[d ^ 1], d), d ^ 1);
            setf(ff, fd);
        }
        return this;
    }
    /* splay this to child of target */
    inline node *splay(node * const target = NULL)
    {
        while (f != target)
        {
            if (target != f->f)
            {
                ( (which() == f->which()) ? f : this )->rotate();
            }
            rotate();
        }
        return this;
    }
    /* 0-based rank */
    inline node *get_k_th(unsigned k)
    {
        node *p = this;
        int rank;
        while (k != (rank = (p->szof(0))))
        {
            if (k < rank) { p = p->ch[0]; }
            else { k -= (rank + 1); p = p->ch[1]; }
        }
        return p->splay(f);
    }
};
