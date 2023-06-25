#ifndef STATE_ATTRIBUTES_H
#define STATE_ATTRIBUTES_H

template<class state>
struct State_traits {
    typedef state state_type;
    typedef typename state_type::value_type value_type;
    typedef typename state_type::iterator iterator;
    typedef typename state_type::const_iterator const_iterator;

    static void resize( const state_type& X, state_type& dXdt ) {
        dXdt.resize( X.size() );
    }
    static bool same_size( const state_type& X1, const state_type& X2 ) {
        return (X1.size() == X2.size());
    }
    static void adjust_size( const state_type& X1, state_type& X2 ) {
        if( !same_size( X1, X2 ) ) resize( X1, X2 );
    }

    static iterator begin( state_type& X ) {
        return X.begin();
    }
    static const_iterator begin( const state_type& X ) {
        return X.begin();
    }
    static iterator end( state_type& X ) {
        return X.end();
    }
    static const_iterator end( const state_type& X ) {
        return X.end();
    }
};

#endif

