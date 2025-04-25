// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );//done

	Account( int initial_deposit );//done
	~Account( void );//done

	void	makeDeposit( int deposit );//done
	bool	makeWithdrawal( int withdrawal );//loading::
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;//done


private:

	static int	_nbAccounts;//done
	static int	_totalAmount;//done
	static int	_totalNbDeposits;//done
	static int	_totalNbWithdrawals;//done

	static void	_displayTimestamp( void );//done

	int				_accountIndex;//done
	int				_amount;//done
	int				_nbDeposits;//done
	int				_nbWithdrawals;//done

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
