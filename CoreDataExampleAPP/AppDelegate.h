//
//  AppDelegate.h
//  CoreDataExampleAPP
//
//  Created by Hitesh Kumar on 03/05/16.
//  Copyright © 2016 Hitesh Kumar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>
#import "Person.h"
#import "Chore.h"
#import "ChoreLog.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;

- (void)saveContext;
- (NSURL *)applicationDocumentsDirectory;

-(Chore *) createChore;
-(ChoreLog *) createChoreLog;
-(Person *) createPerson;  //create "person" manage object

@end

