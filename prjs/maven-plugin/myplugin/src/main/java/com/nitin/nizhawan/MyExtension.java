package com.nitin.nizhawan;

import org.apache.maven.AbstractMavenLifecycleParticipant;
import org.apache.maven.MavenExecutionException;
import org.apache.maven.execution.MavenSession;
import org.codehaus.plexus.component.annotations.Component;


// instead use component.xml, uncomment to use metadata generator @Component( role = AbstractMavenLifecycleParticipant.class, hint = "myextension" )
public class MyExtension
    extends AbstractMavenLifecycleParticipant {

    @Override
    public void afterProjectsRead( MavenSession session )
        throws MavenExecutionException
    {
        System.out.println("project read====================>>>>>>>>>>>>");
    }


}
