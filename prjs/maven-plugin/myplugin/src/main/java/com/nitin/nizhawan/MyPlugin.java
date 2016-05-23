package com.nitin.nizhawan;
import org.apache.maven.plugin.AbstractMojo;

import org.apache.maven.plugin.MojoExecutionException;
import org.apache.maven.plugins.annotations.Mojo;
import org.apache.maven.plugins.annotations.Execute;
@Mojo( name = "mail", requiresProject = false)
//@Execute(phase = "install")
public class MyPlugin extends AbstractMojo
{
 public void execute() throws MojoExecutionException
 {
 getLog().info( "Hey my custom plugin…" );
 }
}
