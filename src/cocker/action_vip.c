#include "cocker_in.h"

int DoAction_vip( struct CockerEnvironment *env )
{
	char		container_vip_file[ PATH_MAX ] ;
	
	int		nret = 0 ;
	
	/* preprocess input parameters */
	Snprintf( env->container_path_base , sizeof(env->container_path_base)-1 , "%s/%s" , env->containers_path_base , env->container_id );
	nret = access( env->container_path_base , F_OK ) ;
	I1TER1( "*** ERROR : container '%s' not found\n" , env->cmd_para.__container_id )
	
	/* modify vip */
	nret = WriteFileLine( env->vip , container_vip_file , sizeof(container_vip_file) , "%s/vip" , env->container_path_base ) ;
	INTER1( "*** ERROR : WriteFileLine vip failed[%d] , errno[%d]\n" , nret , errno )
	EIDTE( "write file [%s] ok\n" , container_vip_file )
	
	return 0;	
}
